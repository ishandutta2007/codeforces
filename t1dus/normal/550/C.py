def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
def ins(n,a):
    s = str(n)
    c = [int(i) for i in s]
    for i in c:
        if i not in a:
            return False
        a = a[a.index(i)+1:]
    return True    
    
a = [int(i) for i in list(input())]
if 0 in a:
    print("YES\n0")
else:
    if 8 in a:
        print("YES\n8")
    else:
        b = [8*i for i in range(1,126)]
        for i in b:
            if ins(i,a):
                print("YES")
                print(i)
                break
        else:
            print("NO")