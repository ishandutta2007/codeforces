n=int(raw_input())

ss=[]
for i in range(n):
    ss+=[raw_input()]

ss=sorted(ss,key=lambda x:len(x))

isok=True
for k in range(n-1):
    if ss[k] not in ss[k+1]:
        isok=False
        break

if isok:
    print "YES"
    for i in ss:
        print i
else:
    print "NO"