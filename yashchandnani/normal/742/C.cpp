#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{   int t1 = a*b;
    int t;
    while(a)
    {
        t = a;
        a = b%a;
        b = t;
    }
    return t1/b;
}
int main(){
    int n,m,j=0;
    cin >> n;
    int a[n+1],flag[n+1],l[n];
    flag[0]=0;
    for (int i = 1; i < n+1; ++i)
    {
    	cin >> a[i];
    	flag[i]=0;
    }
    for (int i = 1; i < n+1; ++i)
    {   
    	if (flag[i]==1){
    		continue;
    	}
    	m= a[i];
    	l[j]=1;
    	while(m!=i){
    		flag[m] = 1;
    		if(flag[a[m]]==1){
    			printf("-1");
    			return 0;
    		}
    		m = a[m];
    		l[j]++;
    	}
    	flag[a[i]]=1;
    	if(l[j]%2==0) l[j]=l[j]/2;
    	j++;
    }
    int max = l[0];
    for (int i = 1; i < j; ++i)
    {  
    	max = gcd(max,l[i]);
    }
    cout<<max;
    return 0;
}