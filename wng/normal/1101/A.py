q=[int(k) for k in raw_input().split(" ")][0]
for nt in range(q):
    l,r,d=[int(k) for k in raw_input().split(" ")]
    if d<l:
        print d
    else:
        print r/d*d+d