r,c=[int(k) for k in raw_input().split(" ")]
t=[["D" for j in range(c+2)] for i in range(r+2)]
for i in range(r):
    z=raw_input().replace(".","D")
    for k in range(c):
        t[i+1][k+1]=z[k];

isok=True
for i in range(r):
    for j in range(c):
        if t[i+1][j+1]=="S":
            if "W" in t[i][j+1]+t[i+1][j]+t[i+1][j+2]+t[i+2][j+1]:
                isok=False
                break
    if not isok:
        break
    
if not isok:
    print "No"
else:
    print "Yes"
    for i in range(1,r+1):
        print "".join(t[i][1:c+1])