n,i=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]

sa=sorted(a)
if i:
    if i<n and sa[i-1]==sa[i]:
        print -1
    else:
        print sa[i-1]
else:
    print (sa[0]-1) if sa[0]>1 else -1