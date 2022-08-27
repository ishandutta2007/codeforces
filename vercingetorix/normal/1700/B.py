ta = int(input())
while ta>0:
    ta-=1
    n = int(input())
    s = input().strip()
    # print(n,s)
    l = len(s)
    sum = 0
    if s[0] != '9':
        sum = int("9"*l)
    else:
        sum = int("1"*(l+1))
    print(sum - int(s))