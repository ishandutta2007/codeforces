n=int(input())
d={v:[] for v in [(0,0),(0,1),(1,0),(1,1)]}
for j,x,y in zip(range(n),map(int,input()),map(int,input())):d[x,y]+=[j+1]
x=n//2
y=len(d[0,1])+len(d[1,1])
x+=x-y
c=min(x,y,len(d[0,1])+len(d[1,0]))
if c%2 != y%2: c -= 1
b=(y-c)//2
a=(x-c)//2
if a<=len(d[0,0]) and 0<=c and b<=len(d[1,1]):
 print(*(d[0,0][:a]+(d[0,1]+d[1,0])[:c]+d[1,1][:b]))
else:
 print(-1)