#include <bits/stdc++.h>
using namespace std;

int num(int x, int y)
{
    if (x>=0&&x<=2&&y>=0&&y<=2) return x * 3 + y + 1;
    if (x==3&&y==1) return 0;
    return -1;
}

pair<int,int> coord(int x)
{
    if (x==0) return {3, 1};
    return {(x+2)/3-1, (x+2)%3};
}

pair<int,int> operator-(pair<int,int> p1, pair<int,int> p2)
{
    return {p1.first - p2.first, p1.second - p2.second};
}

int main()
{
    int n; string str;
    cin >> n >> str;

    vector<pair<int,int>> diff;
    for (int i = 1; i < str.size(); i++) diff.push_back(
        coord(str[i]-'0') - coord(str[i-1]-'0'));

    int ans = 0;

    for (int i = 0; i <= 9; i++)
    {
        int nx, ny;
        tie(nx, ny) = coord(i);
        bool wrong = false;

        for (auto &&e : diff)
        {
            nx += e.first;
            ny += e.second;
            if (num(nx, ny) == -1)
            {
                wrong = true;
                break;
            }
        }

        if (wrong == false) ++ans;
    }

    if (ans == 1) cout << "YES\n";
    else cout << "NO\n";
}