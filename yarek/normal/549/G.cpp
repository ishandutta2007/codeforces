#include <cstdio>
#include <algorithm>
using namespace std;

int t[200000];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
	scanf("%d", t + i);
	t[i] += i;
    }
    sort(t, t + n);
    for(int i = 0; i < n; i++)
	t[i] -= i;
    for(int i = 1; i < n; i++)
	if(t[i] < 0 || t[i] < t[i-1])
	{
	    puts(":(");
	    return 0;
	}
    for(int i = 0; i < n; i++)
	printf("%d ", t[i]);
    puts("");
}