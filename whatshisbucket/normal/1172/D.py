def win(r,c,size):
    if size==0:
        return []
    if r[-1]==c[-1]==size:
        return win(r[:-1],c[:-1],size-1)
    good=(size,c[-1],r[-1],size)
    for i in range(size):
        if r[i]==size:
            r[i]=r[-1]
        if c[i]==size:
            c[i]=c[-1]
    r.pop()
    c.pop()
    return win(r,c,size-1)+[good]
def main():
    n=int(input())
    r=list(map(int,input().split()))
    c=list(map(int,input().split()))
    k=win(r,c,n)
    print(len(k))
    for guy in k:
        print(*guy)
import sys
import threading
sys.setrecursionlimit(2097152)
threading.stack_size(134217728)
main_thread=threading.Thread(target=main)
main_thread.start()
main_thread.join()