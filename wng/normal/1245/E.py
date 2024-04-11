t=[]


def corresp(i,j):
    return 100 - (i*10 + (j if not i%2 else (9-j)))
    
paths=[[i] for i in range(101)]

for i in range(10):
    z=[int(k) for k in input().split(" ")]
    if i%2:
        t+=z[::-1]
    else:
        t+=z
    for j in range(10):
        if z[j]:
            paths[corresp(i,j)]=[corresp(i,j),corresp(i-z[j],j)]

res=[0 for i in range(101)]
for i in range(99,94,-1):
    ri=max(1,6/(100-i))
    #print(i,ri,)
    for j in range(i+1,101):
        ri+=res[j]/(min(6,100-i))
    #    print(j,ri,)
    #print("")
    res[i]=ri

for i in range(94,-1,-1):
    ri=1
    for j in range(i+1,i+7):
        ri+= min([res[k] for k in paths[j]])/6
    res[i]=ri


#print(res)
#print(corresp(9,0))
print(res[1])