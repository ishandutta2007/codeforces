#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec[1000];
int t[1000];
int q[1000];

int main()
{
    int n, T;
    scanf("%d %d", &n, &T);
    for(int i = 0; i < n; i++)
    {
	scanf("%d %d", t + i, q + i);
	vec[T - t[i]].push_back(q[i]);
    }
    for(int i = T; i > 0; i--)
    {
	if(vec[i].size() % 2) vec[i].push_back(0);
	sort(vec[i].begin(), vec[i].end());
	for(int j = 0; j < vec[i].size(); j += 2)
	    vec[i-1].push_back(vec[i][j] + vec[i][j+1]);
    }
    printf("%d\n", *max_element(vec[0].begin(), vec[0].end()));
}