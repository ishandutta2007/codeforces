n=int(input())
a=[]
for i in range(n):
    l=int(input())
    a.append(l)
sum=[a[0],-a[0]]
for i in range(1,n):
    v=[]
    for t in sum:
        v.append((t+a[i])%360)
        v.append((t-a[i])%360)
    v=list(set(v))
    sum=v[0:len(v):1]
if 0 in sum:
    print("YES")
else:
    print("NO")