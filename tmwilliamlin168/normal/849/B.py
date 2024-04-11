n = int(input())
y = list(map(int, input().split()))
for i in range(1, n):
    a = []
    for j in range(n):
        #(y[j]-y[0])/j==(y[i]-y[0])/i
        if (y[j]-y[0])*i!=(y[i]-y[0])*j:
            a.append(j)
    if a:
        ok = len(a)<2 or (y[i]-y[0])*(a[1]-a[0])==(y[a[1]]-y[a[0]])*i
        for j in range(2, len(a)):
            ok &= (y[a[j]]-y[a[0]])*(a[1]-a[0])==(y[a[1]]-y[a[0]])*(a[j]-a[0])
        if ok:
            print("Yes")
            exit()
y = y[::-1]
for i in range(1, n):
    a = []
    for j in range(n):
        #(y[j]-y[0])/j==(y[i]-y[0])/i
        if (y[j]-y[0])*i!=(y[i]-y[0])*j:
            a.append(j)
    if a:
        ok = len(a)<2 or (y[i]-y[0])*(a[1]-a[0])==(y[a[1]]-y[a[0]])*i
        for j in range(2, len(a)):
            ok &= (y[a[j]]-y[a[0]])*(a[1]-a[0])==(y[a[1]]-y[a[0]])*(a[j]-a[0])
        if ok:
            print("Yes")
            exit()
print("No")