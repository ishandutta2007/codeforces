n=input()
a=map(int,raw_input().split())
b=sorted(a)
for l in range(n):
    if a[l]!=b[l]:break
for r in range(n)[::-1]:
    if a[r]!=b[r]:break
if l>=n-1:
    print 'yes'
    print 1,1
else:
    bo=0
    for i in range(l,r+1):
        if a[i]!=b[r+l-i]:bo=1
    if bo:print 'no'
    else:
        print 'yes'
        print l+1,r+1