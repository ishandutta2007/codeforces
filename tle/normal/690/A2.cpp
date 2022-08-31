#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
int T,n,s;
int main()
{
		cin>>n;
		if(n&1) cout<<(n-1)/2<<"\n";
		else
		{
			int ans=0;
			for(int j=0;(1<<j)<=n;j++)
			{
				if(n&(1<<j)) ans=j;
			}
			ans=(n-(1<<ans))/2;
			cout<<ans<<"\n";
		}
}