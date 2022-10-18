R=lambda:map(int,input().split())
n,d=R()
a,b=R()
def get():
    x,y=R()
    return a*x+b*y
s=sorted([(get(),i) for i in range(1,n+1)])
#print(s)
ans=[]
for i in range(n):
    if d>=s[i][0]:
        ans+=[s[i][1]]
        d-=s[i][0]
    else:
        break
print(len(ans))
print(*ans)