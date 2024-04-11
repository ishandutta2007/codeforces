(n,p,k)=map(eval,raw_input().split())
s=''
if max(1,p-k)>1:
    s='<< '+s
for i in range(max(1,p-k),min(n,p+k)+1,1):
    if i!=p:
        s=s+str(i)
    else:
        s=s+'('+str(i)+')'
    if i!=min(n,p+k):
        s=s+' '
if min(n,p+k)<n:
    s=s+' >>'
print s