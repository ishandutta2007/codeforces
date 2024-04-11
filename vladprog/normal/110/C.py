def f(n):
    s=n//7
    n%=7
    s-=n%4
    if s<0:
        return '-1'
    n+=n%4*7
    return '4'*(n//4)+'7'*s

print(f(int(input())))