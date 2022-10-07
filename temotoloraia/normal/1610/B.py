def check (x):
    l = 0
    r = n - 1
    while l <= r:
        if a[l] == x:
            l+=1
            continue
        if a[r] == x:
            r -= 1
            continue
        if a[l] == a[r]:
            l+=1
            r-=1
            continue
        return False
    return True
T = int(input())
for tests in range (T):
    n = int(input())
    S = input()
    a = S.split()
#    print (type (a))
#    print (a)
    l = 0
    r = n - 1;
    while l <= r:
        if a[l] != a[r]:
            break
        else:
            l += 1
            r -= 1
    if l >= r:
        print ("YES")
        continue
    if check (a[l]) or check (a[r]):
        print ("YES")
    else:
        print ("NO")