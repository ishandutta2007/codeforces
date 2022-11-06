n,m=[int(k) for k in raw_input().split(" ")]
v=[]
for i in range(m):
    v+=[[int(k) for k in raw_input().split(" ")]]

print "".join([str(k%2) for k in range(n)])