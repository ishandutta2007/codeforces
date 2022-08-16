x,y,l,r = map(int,input().split())
a = []
b = []
cur = 1
while (cur <= 1e18):
    a.append(cur)
    cur *= x
cur = 1
while cur <= 1e18:
    for i in a:
        if l <= i+cur <= r:
            b.append(i+cur)
    cur *= y
b.sort()

ans = 0

# b = [7]
# print(b)

for i in range(1,len(b)):
    ans = max(ans,b[i]-b[i-1]-1)
    
if len(b) > 0:
    ans = max(ans,b[0]-l)
    ans = max(ans,r-b[-1])

else:
    ans = max(ans,r-l+1)
    
print(ans)