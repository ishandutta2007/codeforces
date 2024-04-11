R=lambda:map(int,raw_input().split())
n,s,t=R()
a=R()
r=0
while (a[s-1]!=0)&(s!=t):r,a[s-1],s=r+1,0,a[s-1]
print [-1,r][s==t]