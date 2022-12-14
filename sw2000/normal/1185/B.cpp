#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

void judge()
{
	string a, b;
	cin >> a >> b;
	int la = a.length(), lb = b.length(), cnt = 1;
	if (la>lb || a[0] != b[0])
	{
		printf("NO\n");
		return;
	}
	for (int i = 1; i<lb; i++)
	{
	    if(cnt<la&&b[i]==a[cnt])
        {
            cnt++;
            continue;
        }
		if (b[i] != a[cnt - 1])
		{
            printf("NO\n");
            return;
		}
	}
	if(cnt==la)
    {
        printf("YES\n");
        return;
    }
    printf("NO\n");
    return;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		judge();
	}
	return 0;
}