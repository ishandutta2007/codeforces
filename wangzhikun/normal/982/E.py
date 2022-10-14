ix = 0
iy = 0
ansx = 0
ansy = 0
suc = 0
x = 0
y = 0
dx = 0
dy = 0
bloc = 0
def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b,a%b)
def exgcd(a,b,x,y):
	if b == 0:
		x[0] = 1
		y[0] = 0
		return a;
	d = exgcd(b, a%b, y, x);
	y[0]-=a/b*x[0];
	return d;
def opt():
	global ansx,ansy,suc
	if not suc:
		print -1
	else:
		ansx%=(2*a);
		ansy%=(2*b);
		if (e == -1):
			ansx = a-ansx;
		if (f == -1):
			ansy = b-ansy;
		print str(ansx)+' '+str(ansy)
	exit()
a,b,c,d,e,f = [int(i) for i in raw_input().split()]
if e == -1:
	c = a-c;
if f == -1:
	d = b-d;
if e*f == 0:
	if ( e == 0 and (c == a or c == 0)):
		suc = 1
		ansx =c
		ansy = b
	if (f == 0 and (d == b or d == 0)):
		suc = 1
		ansx =a
		ansy = d
	opt()
ix = a-c;iy = b-d;
cx = [0]
cy = [0]
exgcd(a,b,cx,cy);
x = cx[0]
y = cy[0]
y*=-1;
if ((iy-ix)%(x*a-y*b) != 0):
	opt();
dx = (iy-ix)/(x*a-y*b);
x*=dx;
y*=dx;
x = ix+x*a+c;
y = iy+y*b+d;
bloc = a*b/gcd(a,b);
dx = (x%bloc+bloc)%bloc;
y += (dx-x);
x = dx;
dx = max((c-x+bloc-1)/bloc,(d-y+bloc-1)/bloc);
x+=dx*bloc;
y+=dx*bloc;
ansx = x;
ansy = y;
suc = 1;
opt()