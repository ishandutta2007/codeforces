#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline



def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y
        
def s2(x):
    if x<10:
        return x
    else:
        return s2(sum([int(k) for k in str(x)]))

t=int(input())
print(s2(t))