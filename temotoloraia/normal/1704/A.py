T = int(input())
for tests in range (T):
    S = input()
    ss = S.split()
    n = int(ss[0])
    m = int(ss[1])
    A = input()
    B = input()
    if n < m:
        print ("NO")
        continue
    ok = 0
    while m > 1:
        if A[n-1] != B[m-1]:
            print ("NO")
            ok = 1
            break
        n -= 1
        m -= 1
    if ok == 1:
        continue
    ans = "NO"
    for i in range (0, n):
        if A[i] == B[0]:
            ans = "YES"
            break
    print (ans)