#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
struct pt{ int x,y;pt(int a=0, int b=0):x(a),y(b){}};
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
bool operator == (pt a, pt b){ return a.x==b.x && a.y==b.y;}
ll sq(pt x){ return (ll)x.x*x.x+(ll)x.y*x.y;}
db abs(pt x){ return sqrt(sq(x));}
struct ptdb{ db x,y;ptdb(db a=0, db b=0):x(a),y(b){}};
ptdb operator * (pt a, db b){ return ptdb(b*a.x,b*a.y);}
ptdb operator * (ptdb a, db b){ return ptdb(b*a.x,b*a.y);}
ptdb operator + (ptdb a, pt b){ return ptdb(a.x+b.x,a.y+b.y);}
int main()
{
    int R;pt a,b;
    scanf("%i %i %i %i %i",&R,&a.x,&a.y,&b.x,&b.y);
	if((ll)R*R<=sq(a-b)) printf("%i %i %i\n",a.x,a.y,R);
	else if(a==b) cout << fixed << setprecision(12) << (db)a.x+(db)R/2 << " " << a.y << " " << (db)R/2 << "\n";
	else
	{
		db r=(abs(a-b)+R)/2;
		ptdb tmp=(((b-a)*(1/abs(a-b)))*(-r+abs(a-b)))+a;
		cout << fixed << setprecision(12) << tmp.x << " " << tmp.y << " " << r << "\n";
	}
	return 0;
}