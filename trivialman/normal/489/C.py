m,s = map(int,input().split())
if(s==0 and m==1):
    print('0 0')
elif(s==0 or s>m*9):
    print('-1 -1')
else:
    ans1='9'*((s-1)//9)
    if(len(ans1)==m-1):
        ans1=str((s-1)%9+1)+ans1
    else:
        ans1='1'+'0'*(m-len(ans1)-2)+str((s-1)%9)+ans1
    ans2='9'*((s-1)//9)+str((s-1)%9+1)
    if(len(ans2)<m):
        ans2=ans2+'0'*(m-len(ans2))
    print(ans1,ans2)
'''

# 
def document_it(func):
    def new_function(*args, **kwargs):
        print("Runing function: ", func.__name__)
        print("Positional arguments: ", args)
        print("Keyword arguments: ", kwargs)
        result = func(*args, **kwargs)
        print("Result: " ,result)
        return result
    return new_function

# 
def add_ints(a, b):
    return a + b

cooler_add_ints = document_it(add_ints) #
cooler_add_ints(3,5)

# 
@document_it
def add_ints(a, b):
    return a + b
add_ints(4,6)
'''