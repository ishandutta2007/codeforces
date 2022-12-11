#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int x[100];
int a[100][100];
int sum[100];
char s[101];
int k[100];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
	scanf("%s", s);
	for(int j = 0; j < n; j++)
	    a[i][j] = s[j] - '0';
    }
    for(int i = 0; i < n; i++)
	scanf("%d", k + i);
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
	for(int j = 0; j < n; j++)
	    if(sum[j] == k[j])
	    {
		ans.push_back(j);
		for(int l = 0; l < n; l++)
		    sum[l] += a[j][l];
	    }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
	printf("%d ", ans[i] + 1);
    puts("");
}