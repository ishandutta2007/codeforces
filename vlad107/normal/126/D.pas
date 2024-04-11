{$r-,q-,s-,i-,o+}
const  
  MAXF=90;
  
var
  fib:array[0..MAXF+1]of int64;
  n,res:int64;
  q,i,x,y,z,tt:longint;
  f:array[0..MAXF+1,0..2,0..2]of int64;
  a:array[0..MAXF+1]of longint;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(tt);
  fib[1]:=1;
  fib[2]:=2;
  for i:=3 to MAXF do fib[i]:=fib[i-1]+fib[i-2];
  while (tt>0)do begin
    dec(tt);
    read(n);
    for i:=MAXF downto 1 do 
      if (n>=fib[i])then begin
        n:=n-fib[i];
        a[MAXF-i+1]:=1;
      end else a[MAXF-i+1]:=0;
      
    fillchar(f,sizeof(f),$0);
    f[1][a[1],a[2]]:=1;
    for i:=1 to MAXF-2 do 
      for x:=0 to 2 do 
        for y:=0 to 2 do begin
          if (f[i][x][y]=0)then continue;
          z:=a[i+2];
          if (x=2)or(x=1)then 
            if (y<2)and(z<2)then f[i+1][y+1][z+1]:=f[i+1][y+1][z+1]+f[i][x][y];
          if (x=0)or(x=1)
            then f[i+1][y][z]:=f[i+1][y][z]+f[i][x][y];
        end;
    res:=0;
    for x:=0 to 1 do
      for y:=0 to 1 do 
        res:=res+f[MAXF-1][x][y];
    writeln(res);
  end;
  close(output);close(input);
end.