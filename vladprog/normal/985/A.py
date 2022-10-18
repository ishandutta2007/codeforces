n=int(input())
r1,r2=0,0
p=list(map(int,input().split()))
p.sort()
for i in range(n//2):
    r1+=abs(2*i+1-p[i])
    r2+=abs(2*i+2-p[i])
print(min(r1,r2))