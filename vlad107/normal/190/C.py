n=input()
s=map(str,raw_input().split(' '))
if (s==['int']):
    print 'int'
    exit(0)
if (s[0]=='int'):
    print 'Error occurred'
    exit(0)
p=[2]
ans=s[0]
for t in s[1:]:
    if (len(p)==0):
        print 'Error occurred'
        exit(0)
    x=p[len(p)-1]
    if (x==2):
        ans+='<'
    elif (x==1):
        ans+=','
    ans+=t
    p[len(p)-1]-=1
    if (t=='pair'):
        p.append(2)
    while ((len(p)>0)and(p[len(p)-1]==0)):
        p.pop()
        ans+='>'
        
if (len(p)==0):
    print ans
else:
    print 'Error occurred'