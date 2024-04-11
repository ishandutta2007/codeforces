n,p,w,d=map(int,input().split())
x=-1
for y in range(w):
	if (p-y*d)%w==0:
		x=(p-y*d)//w
		break
if x<0 or n-x-y<0:
	print(-1)
else:
	print(x,y,n-x-y)