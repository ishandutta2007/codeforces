#include <iostream>
using namespace std;

const int N = (int)1e6 + 10;

bool used[N];
bool to[N];
int ans[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
                     
    for (int i = 30; i >= 0; i--)
    {
    	int t = (1 << i);
    	if (t <= n)
    	{
    		int j = t - 1;
    		for (int s = t; s <= n && !used[s]; s++)
    		{
    			ans[s] = j; 
    			ans[j] = s;
    			used[s] = used[j] = 1;
    			j--;
    		}
    	}	
    }
             


	long long res = 0;
	for (int i = 0; i <= n; i++)
		res += (long long)(i ^ ans[i]);

	cout << res << endl;
	for (int i = 0; i <= n; i++)
		printf("%d ", ans[i]);

	return 0;
}