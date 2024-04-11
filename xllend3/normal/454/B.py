n=input()
a=map(int,raw_input().split())
bo=0
co=0
for i in range(n-1):
    if a[i]>a[i+1]:
        bo=i+1
        break
if bo==0:
    print 0
else:
    for i in range(bo,n-1):
        if a[i]>a[i+1]:
            co=i+1
    if co==0 and a[n-1]<=a[0]:
        print n-bo
    else:
        print -1