n,k=[int(k) for k in raw_input().split(" ")]
s=raw_input()


nbo=0
nbt=0

res=[]
for c in s:
    ta= 1 if c=="(" else -1
    if (ta==1 and k-len(res)>nbo) or (ta==-1 and nbo):
        nbo+=ta
        res+=[c]
    if len(res)==k:
        break

print "".join(res)