a,b=map(int,input().split())
notes=int((2*(a+b)-(2*a+2*b)**(.5)+1)**.5)
if a+b==0:
    notes=0
alist=[]
blist=[]
aleft=a
for i in range(notes):
    if aleft>=notes-i:
        alist.append(notes-i)
        aleft=aleft+i-notes
    else:
        blist.append(notes-i)
astr=""
for guy in alist:
    astr+=str(guy)+" "
bstr=""
for guy in blist:
    bstr+=str(guy)+" "
print(len(alist))
print(astr[:-1])
print(len(blist))
print(bstr[:-1])