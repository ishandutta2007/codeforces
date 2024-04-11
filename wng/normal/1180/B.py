n=[int(k) for k in input().split(" ")][0]

a=[int(k) for k in input().split(" ")]
mk=0
dk=0
for k in range(n):
    a[k]=min(a[k],-a[k]-1)
    if mk>a[k]:
        mk=a[k]
        dk=k

if n%2:
    a[dk]=-a[dk]-1

print(" ".join([str(k) for k in a]))