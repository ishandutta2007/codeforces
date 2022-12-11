#include <bits/stdc++.h>
using namespace std;

const int N = 500000;
const int mod = 1000000007;
char s[N];

struct block;

block *bl[N];
int poww[N];
stack<block*> blocks;

void next(int &it)
{
    if(blocks.empty()) it++;
    else bl[it++] = blocks.top();
}

int power(int a, int b)
{
    if(b == 0) return 1;
    if(b & 1) return 1LL * a * power(a, b - 1) % mod;
    return power(1LL * a * a % mod, b / 2);
}

int inv(int a)
{
    return power(a, mod - 2);
}

struct expr
{
    int a, b;
    int val;
    virtual int _get(int A, int B) { return 0; };
    int get(int A, int B)
    {
        A = max(a, A);
        B = min(b, B);
        if(a == A && b == B)
        {
            //printf("expr get(%d %d) = %d\n", A, B, val);
            return val;
        }
        return _get(A, B);
    }
    expr(int A, int B) : a(A), b(B) { }
    expr() = default;
};

struct num : expr
{
    vector<int> pref;
    num(int &it)
    {
        a = it;
        val = 0;
        pref.push_back(0);
        while(isdigit(s[it]))
        {
            val = (1LL * val * 10 + s[it] - '0') % mod;
            next(it);
            pref.push_back(val);
        }
        b = it;
//         printf("num %d - %d = %d\n", a, b, val);
    }
    int _get(int A, int B)
    {
        int ans = (pref[B-a] - 1LL * pref[A-a] * poww[B-A]) % mod;
        if(ans < 0) ans += mod;
        //printf("num get(%d %d) = %d\n", A, B, ans);
        return ans;
    }
};

struct prod : expr
{
    vector<expr*> vec;
    vector<int> res;
    prod(int &it);
    int _get(int A, int B)
    {
        auto e = new expr(A, B);
        auto it1 = upper_bound(vec.begin(), vec.end(), e, [](expr *a, expr *b) { return a->a < b->a; });
        auto it2 = lower_bound(vec.begin(), vec.end(), e, [](expr *a, expr *b) { return a->b < b->b; });
        delete e;
        int ans = 1;
        if(it2 > it1)
            ans = 1LL * res[it2 - vec.begin()] * inv(res[it1 - vec.begin()]) % mod;
        if(it2 != vec.end()) ans = 1LL * ans * (*it2)->get(A, B) % mod;
        if(it1 != vec.begin() && --it1 != it2) ans = 1LL * ans * (*it1)->get(A, B) % mod;
        //printf("prod get(%d %d) = %d\n", A, B, ans);
        return ans;
    }
};

struct block : expr
{
    vector<expr*> vec;
    vector<int> res;
    block(int &it)
    {
        val = 0;
        a = it;
        assert(s[it] == '(');
        next(it);
        blocks.push(this);
        res.push_back(0);
        while(true)
        {
            vec.push_back(new prod(it));
            val = (val + vec.back()->val) % mod;
            res.push_back(val);
            if(s[it] != '+') break;
            else next(it);
        }
        blocks.pop();
        assert(s[it] = ')');
        next(it);
        b = it;
//         printf("block %d - %d = %d\n", a, b, val);
    }
    int _get(int A, int B)
    {
        if(a == A || b == B) return -1;
        auto e = new expr(A, B);
        auto it1 = upper_bound(vec.begin(), vec.end(), e, [](expr *a, expr *b) { return a->a < b->a; });
        auto it2 = lower_bound(vec.begin(), vec.end(), e, [](expr *a, expr *b) { return a->b < b->b; });
        delete e;
        int ans = 0;
        if(it2 > it1)
            ans = res[it2 - vec.begin()] - res[it1 - vec.begin()];
        if(ans < 0) ans += mod;
        if(it2 != vec.end()) ans = (ans + (*it2)->get(A, B)) % mod;
        if(it1 != vec.begin() && --it1 != it2) ans = (ans + (*it1)->get(A, B)) % mod;
        //printf("block get(%d %d) = %d\n", A, B, ans);
        return ans;
    }
};

prod::prod(int &it)
{
    val = 1;
    a = it;
    res.push_back(1);
    while(true)
    {
        if(s[it] == '(') vec.push_back(new block(it));
        else vec.push_back(new num(it));
        val = 1LL * val * vec.back()->val % mod;
        res.push_back(val);
        if(s[it] != '*') break;
        else next(it);
    }
    b = it;
//     printf("prod %d - %d = %d\n", a, b, val);
}

int main()
{
    poww[0] = 1;
    for(int i = 1; i < N; i++)
        poww[i] = poww[i-1] * 10LL % mod;
    scanf("%s", s + 1);
    s[0] = '(';
    s[strlen(s)] = ')';
    int i = 0;
    new block(i);
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if((!isdigit(s[a]) && s[a] != '(') || (!isdigit(s[b]) && s[b] != ')') || bl[a] != bl[b])
        {
            puts("-1");
            continue;
        }
        printf("%d\n", bl[a]->get(a, b + 1));
    }
}