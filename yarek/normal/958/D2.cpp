#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ld> vec;

vec operator*(const vec &a, const vec &b)
{
    vec ans(a.size());
    for(int i = 0; i < ans.size(); i++)
        ans[i] = a[i] * b[i];
    return ans;
}

vec operator+(const vec &a, const vec &b)
{
    vec ans(a.size());
    for(int i = 0; i < ans.size(); i++)
        ans[i] = a[i] + b[i];
    return ans;
}

vec operator-(const vec &a, const vec &b)
{
    vec ans(a.size());
    for(int i = 0; i < ans.size(); i++)
        ans[i] = a[i] - b[i];
    return ans;
}

vec operator*(const vec &a, const ld &b)
{
    vec ans(a.size());
    for(int i = 0; i < ans.size(); i++)
        ans[i] = a[i] * b;
    return ans;
}

vec operator/(const vec &a, const ld &b)
{
    vec ans(a.size());
    for(int i = 0; i < ans.size(); i++)
        ans[i] = a[i] / b;
    return ans;
}

ld sum(const vec &v)
{
    return accumulate(v.begin(), v.end(), (ld)0);
}

ld len(vec v)
{
    return sqrt(sum(v * v));
}

ld dot(vec a, vec b)
{
    return sum(a * b);
}

vec cast(const vec &v, const vector<vec> &ortho)
{
    vec ans(v.size());
    for(const auto &u: ortho)
        ans = ans + u * dot(v, u);
    return ans;
}

vector<vec> orthogonalize(const vector<vec> &v)
{
    const ld eps = 1e-6;
    vector<vec> base;
    for(const auto &u: v)
    {
        auto c = u - cast(u, base);
        auto l = len(c);
        if(l > eps) base.push_back(c / l);
    }
    for(auto &x: base)
        for(auto &y: base)
            assert(&x == &y || dot(x, y) < eps);
    return base;
}

const int N = 30001;
int anss[N];

int main()
{
    srand(14);
    int m, d;
    scanf("%d %d", &m, &d);
    vector<ld> mult;
    for(int i = 0; i < d * d; i++)
        mult.push_back((ld)rand() / RAND_MAX);
    vector<vec> e(d, vec(d));
    for(int i = 0; i < d; i++)
        e[i][i] = 1;
    vector<pair<pair<int, ld>, int>> vrep;
    for(int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        vector<vec> space;
        while(k--)
        {
            vec v(d);
            for(int j = 0; j < d; j++)
                scanf("%Lf", &v[j]);
            space.push_back(v);
        }
        auto ortho = orthogonalize(space);
        vector<ld> rep;
        for(const auto &u: e)
        {
            auto c = cast(u, ortho);
            for(int j = 0; j < d; j++)
                rep.push_back(c[j]);
        }
        vrep.emplace_back(make_pair(ortho.size(), sum(rep * mult)), i);
    }
    sort(vrep.begin(), vrep.end());
    vector<vector<int>> vec;
    const ld eps = 1e-10;
    for(int i = 0; i < vrep.size(); i++)
        if(i == 0 || abs(vrep[i].first.second - vrep[i-1].first.second) > eps)
            vec.push_back({ vrep[i].second });
        else vec.back().push_back(vrep[i].second);
    for(auto &v: vec)
        sort(v.begin(), v.end());
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++)
        for(auto x: vec[i]) anss[x] = i + 1;
    for(int i = 0; i < m; i++)
        printf("%d ", anss[i]);
    puts("");
}