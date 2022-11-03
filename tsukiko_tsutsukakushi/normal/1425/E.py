N,K = map(int,input().split())
A = list(map(int,input().split()))
D = list(map(int,input().split()))
if K >= 2:
    print(max(0,sum(A)-min(D[:N-1]),A[N-1]-D[N-1]))
if K == 0:
    S = 0
    ans = 0
    for i in range(N)[::-1]:
        S += A[i]
        ans = max(ans,S-D[i])
    print(ans)
if K == 1:
    minD = [D[0]]
    csA = [A[0]]
    for i in range(1,N):
        minD.append(min(minD[-1],D[i]))
        csA.append(csA[-1]+A[i])
    csinvA = [A[N-1]]
    for i in range(N-1)[::-1]:
        csinvA.append(csinvA[-1]+A[i])
    csinvA = csinvA[::-1]
    right = []
    S = 0
    for i in range(N)[::-1]:
        S += A[i]
        right.append(S-D[i])
    right = right[::-1]
    rightM = [right[N-1]]
    for i in range(N-1)[::-1]:
        rightM.append(max(rightM[-1],right[i]))
    rightM = rightM[::-1]
    ans = 0
    z = 0
    for i in range(N)[::-1]:
        x = 0
        y = csA[i]-minD[i]
        if y >= 0:
            x += y
        x += z
        if i != N-1 and i != 0:
            ans = max(ans,x)
        z = max(z,right[i])
    for i in range(N-2):
        ans = max(ans,right[i+1])
        ans = max(ans,rightM[0]-D[i+1])
        ans = max(ans,rightM[i+2])
        ans = max(ans,rightM[0]-A[i+1])
    print(ans)