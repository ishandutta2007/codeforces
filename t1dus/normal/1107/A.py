for _ in range(int(input())):
    n = int(input())
    s = input()
    x = int(s[0])
    cnt = 0
    for i in range(1,n-1):
        if int(s[i]) > 0:
            cnt += 1
    if cnt or int(s[0]) < int(s[n-1]):
        print("YES")
        print(2)
        print(s[0],s[1:])
    else:
        print("NO")