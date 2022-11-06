n=int(raw_input())
s=raw_input()
res=0
maxcool=0
for i in range(2,n/2+1):
    if s[:i]*2==s[:2*i]:
        maxcool=i
res=n
if maxcool>1:
    res-=maxcool-1
print res