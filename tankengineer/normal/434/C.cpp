#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct trie
{
    char ch;
    int son,next,father,suffix;
    vector <int> danger;

    int sum;
};

trie a[205];

int now, m;

void clear(int x)
{
    a[x].son=a[x].next=0;
    a[x].danger.clear();
}

void insert(char *s,int l,int t,int x)
{
    if (!a[x].son)
    {
        a[x].son=++m;
        clear(m);
        a[m].father=x;
        a[m].ch=s[t];
        if (t+1==l)
            a[m].danger.push_back(now);
        else
            insert(s,l,t+1,m);
        return;
    }
    int i=a[x].son;
    while (1)
    {
        if (!a[i].next || a[i].ch==s[t])
            break;
        i=a[i].next;
    }
    if (a[i].ch==s[t] && t+1==l)
        a[i].danger.push_back(now);
    else if (a[i].ch==s[t])
        insert(s,l,t+1,i);
    else
    {
        a[i].next=++m;
        clear(m);
        a[m].father=x;
        a[m].ch=s[t];
        if (t+1==l)
            a[m].danger.push_back(now);
        else
            insert(s,l,t+1,m);
    }
}

int q[205];

int child(int x,char ch)
{
    for (int i=a[x].son;i;i=a[i].next)
        if (a[i].ch==ch)
            return(i);
    if (x==1)
        return(1);
    return(child(a[x].suffix,ch));
}

void build_trie()
{
    int l,r;
    l=r=1;
    q[1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=a[x].son;i;i=a[i].next)
            q[++r]=i;
    }
    a[1].suffix=1;
    for (int i=2;i<=r;i++)
    {
        int x=q[i];
        if (a[x].father==1)
        {
            a[x].suffix=1;
            continue;
        }
        a[x].suffix=child(a[a[x].father].suffix,a[x].ch);
        for (int j=0;j<(int)a[a[x].suffix].danger.size();j++)
            a[x].danger.push_back(a[a[x].suffix].danger[j]);
    }
}

int n, base, k;

void read(char *s) {
    int l;
    scanf("%d", &l);
    s[l] = '\0';
    for (int i = 0; i < l; ++i) {
        int a;
        scanf("%d", &a);
        s[i] = a + 'a';
    }
}

int v[205];
char l[205], r[205], s[205];

const int MOD = 1000000007;

int curl;
char cur[205];

int f[205][205][505];

int dp(int i, int state, int sum, bool cmp, bool first) {
    if (sum > k) {
        return 0;
    }
    if (i == 0) {
        return 1;
    }
    if (!first && !cmp && f[i][state][sum] != -1) {
        return f[i][state][sum];
    }
    int ret = 0;
    int r = cur[curl - i] - 'a';
    for (int d = first; d < base; ++d) {
        if (cmp && d > r) {
            continue;
        }
        int nstate = child(state, d + 'a'),
            nsum = sum + a[nstate].sum;
        bool ncmp = cmp && d == r;
        ret += dp(i - 1, nstate, nsum, ncmp, false);
        if (ret >= MOD) {
           ret -= MOD;
        }
    }
    if (!cmp && !first) {
        f[i][state][sum] = ret;
    }
    return ret;
}

int cal(char *s) {
    int l = strlen(s);
    curl = l;
    for (int i = 0; i < l; ++i) {
        cur[i] = s[i];
    }
    int ret = 0;
    while (curl) {
        ret += dp(curl, 1, 0, curl == l, true);
        --curl;
        if (ret >= MOD) {
            ret -= MOD;
        }
    }
    return ret;
}

int check(char *s) {
    int sum = 0, cur = 1, l = strlen(s);
    for (int i = 0; i < l; ++i) {
        cur = child(cur, s[i]);
        sum += a[cur].sum;
    }
    return sum <= k;
}

int main()
{
    memset(f, -1, sizeof(f));
    scanf("%d%d%d", &n, &base, &k);
    read(l), read(r);
    clear(m=1);
    for (int i=0;i<n;i++)
    {
        read(s);
        scanf("%d", v + i);
        now=i;
        insert(s,strlen(s),0,1);
    }
    build_trie();
    for (int i = 1; i <= m; ++i) {
        a[i].sum = 0;
        for (int j = 0; j < (int)a[i].danger.size(); ++j) {
            a[i].sum += v[a[i].danger[j]];
        }
    }
    long long ansl = cal(l), ansr = cal(r);
    cout << ((ansr - ansl + check(l)) % MOD + MOD) % MOD << endl;
    /*
for (int i = 1; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
        l[0] = i + 'a', l[1] = j + 'a';
        l[2] = '\0';
        if (!check(l)) {
            cout << i << j << endl;
        }
    }
}
for (int i = 1; i <= m; ++i) {
    cout << i << ' ' << a[i].sum << endl;
    for (int j = 0; j < base; ++j) {
        cout << child(i, j + 'a');
    }
    cout << endl;
}
*/
    return 0;
}