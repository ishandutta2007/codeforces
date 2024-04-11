#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct wall
{
	int x, y, z;
};
struct oboi
{
	int x, y, c;
};
wall mas[1000];
oboi ob[1000];
int main()
{
	int n, m, rez=0;
	cin >> n;
	for ( int i=0; i<n; i++ )
		cin >> mas[i].x >> mas[i].y >> mas[i].z;
	cin >> m;
	for ( int i=0; i<m; i++ )
		cin >> ob[i].x >> ob[i].y >> ob[i].c;
	for ( int i=0; i<n; i++ )
	{
		int x1=(mas[i].x+mas[i].y)*2;
		int y1=mas[i].z;
		int mi=-1;
		for ( int s=0; s<m; s++ )
		{
			int count=ob[s].x/y1;
			count*=ob[s].y;
			if ( count!=0 )
			{
				int all=(x1+count-1)/count;
				int t=all*ob[s].c;
				if ( t<mi||mi==-1 )
					mi=t;
			}
		}
		if ( mi!=-1 )	
			rez+=mi;
	}
	cout << rez;
	return 0;
}