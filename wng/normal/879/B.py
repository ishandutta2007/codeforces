n,k=[int(ii) for ii in raw_input().split(" ")]
a=[int(ii) for ii in raw_input().split(" ")]


if k>=n:
    print n #[i for i in range(n) if a[i]==n][0]+1
else:
    nbw=0
    toplay=0
    chall=1
    while nbw<=k:
        if a[toplay]==n or nbw==k:
            print a[toplay]
            break
        if a[toplay]>a[chall]:
            nbw+=1
        else:
            toplay=chall
            nbw=1
        chall+=1