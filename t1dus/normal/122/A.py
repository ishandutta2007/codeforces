def lucky(n):
    x = str(n)
    for i in x:
        if i != "4" and i != "7":
            return False
    return True
def almost_lucky(n):
    if lucky(n) == True:
        return True
    for j in range(1,n+1):
        if lucky(j)==True:
            if n%j == 0:
                return True
    return False
if almost_lucky(int(input())) == True:
    print("YES")
else:
    print("NO")