#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int a, b;
string s;

bool solve()
{
    vector<int>v;
    int flag=0;
	for (int i = 0, cnt = 0; i<s.length(); i++)
	{
		if (s[i] == '.')cnt++;
		else
		{
			if (cnt >= b&&cnt<a)return false;
			else if(cnt>=a)
            {
                v.push_back(cnt);
                if(cnt>=b*2)flag++;
            }
            cnt=0;
		}
	}
	if(flag>1)return false;
    if(v.empty())return false;

	sort(v.begin(),v.end());
	if(a>=b*2)
    {
        if(v[0]<a+b*2-1)return true;
        else return false;
    }
    int cnt=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<2*b)cnt++;
    }
    int ma=*(v.end()-1);
    if(ma<2*b)
    {
        if(cnt&1)return true;
        else return false;
    }
    if(cnt&1)
    {
        if(ma>=2*a&&ma<=a+3*b-2)return true;
        return false;
    }

    if(ma<=a+2*b-2||ma>=a*3&&ma<=a+4*b-2)return true;
    return false;

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cin >> s;
		s += "X";
		if (solve())cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}