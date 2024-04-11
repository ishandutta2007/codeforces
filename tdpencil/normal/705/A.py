n=int(input())
if n < 2:
    print("I hate it")
else:
    s=""
    for i in range(1, n):
        if i%2==1:
            s+="I hate that "
        if i%2==0:
            s+="I love that "
    if n%2==0:
        s+="I love it"
    else:
        s+="I hate it"
    print(s)