s = input()
n = len(s)
k = int(input())
if "*" in s:
    x = s.index("*")
    lol = ""
    ind = -1
    char = ""
    for i in range(n):
        if s[i] in ["*","?"]:
            continue
        if i == n-1:
            lol += s[i]
        elif i  == x-1:
            ind = len(lol)
            char = s[i]
        elif s[i+1] in ["*","?"]:
            continue
        else:
            lol += s[i]
    if len(lol) > k:
        print("Impossible")
    else:
        print(lol[:ind]+char*(k-len(lol))+lol[ind:])
else:
    cnt = 0
    for i in s:
        if i != "?":
            cnt += 1
    if cnt < k:
        print("Impossible")
    else:
        lol = ""
        for i in range(len(s)):
            if s[i] == "?":
                continue
            if i == n-1 or s[i+1] != "?":
                lol += s[i]
                continue
            if cnt > k:
                cnt -= 1
                continue
            lol += s[i]
        if cnt > k:
            print("Impossible")
        else:
            print(lol)