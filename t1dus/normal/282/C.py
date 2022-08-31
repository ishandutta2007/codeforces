def conv(a,b):
    if len(a) != len(b):
        return False
    if a == b:
        return True
    return not('1' not in a or '1' not in b)
    
a = input()
b = input()
if conv(a,b):
    print("YES")
else:
    print("NO")