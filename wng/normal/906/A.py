n=int(raw_input())

ls=[]
for i in range(n):
    ls+=[[k for k in raw_input().split(" ")]]
    
g=set()
b=set("abcdefghijklmnopqrstuvwxyz")
nbcr=0
det=False
nbm=0
jj=0
for k in ls:
    jj+=1
    if k[0]==".":
        for j in k[1]:
            g.add(j)
            b.discard(j)
    if k[0]=="!":
        b=b.intersection(k[1])
        nbcr+=1
    if k[0]=="?":
        if jj!=n:
            b.discard(k[1])
            g.add(k[1])
            nbcr+=1
        else:
            b=set(k[1])
    if len(b)==1 and not det:
        det=True
        nbm=nbcr
  #  print k,len(b),len(g),b,det
print nbcr-nbm