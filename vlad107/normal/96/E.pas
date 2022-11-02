{$r-,q-,s-,i-,o+}
{$M 2000000}
const 
  base=1000000007;
var
  f:array[0..1111,0..1,0..1111]of longint;
  i,n,tt,k,res:longint;
  ch:char;
  s:ansistring;
  procedure next(x,y,let:longint;var x2,y2:longint);
    begin
      let:=ord((let=4)or(let=7));
      if (let=0)then begin
        if (y<>0)then inc(y);
        x2:=x;y2:=y;
        exit;
      end;
      if (y<>0)and(y<=k)then x:=1;
      x2:=x;y2:=1;
    end;
  function rec(x,y,z:longint):longint;
    var
      y2,z2,cr,res:longint;
    begin
      if (f[x][y][z]<>-1)then begin
        rec:=f[x][y][z];
        exit;
      end;
      if (x=0)then begin
        f[x][y][z]:=y;
        rec:=f[x][y][z];
        exit;
      end;
      res:=0;
      next(y,z,0,y2,z2);
      cr:=rec(x-1,y2,z2);
      res:=(int64(cr)*8)mod base;
      next(y,z,4,y2,z2);
      cr:=rec(x-1,y2,z2);
      res:=(int64(cr)*2+res)mod base;
      f[x][y][z]:=res;
      rec:=res;
    end;
  function solve:longint;
    var
      start,finish,j2,k2,i,j,k,res,t:longint;
    begin
      n:=length(s);
      j:=0;k:=0;
      res:=0;
      for i:=0 to n-1 do begin
        start:=0;
        finish:=ord(s[i+1])-49;
        for t:=start to finish do begin
          next(j,k,t,j2,k2);
          res:=(res+rec(n-i-1,j2,k2))mod base;
        end;
        next(j,k,finish+1,j2,k2);
        j:=j2;k:=k2;
      end; 
      solve:=res;
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(tt,k);
  fillchar(f,sizeof(f),$FF);
  while (tt>0)do begin
    dec(tt);
    read(ch);
    while not(ch in ['0'..'9'])do read(ch);
    s:='';
    while (ch in ['0'..'9'])do begin
      s:=s+ch;
      read(ch);
    end;
    res:=base-solve;   
    while not(ch in['0'..'9'])do read(ch);
    s:='';
    while (ch in ['0'..'9'])do begin
      s:=s+ch;
      read(ch);
    end;
    i:=length(s);
    while (s[i]='9')do begin
      s[i]:='0';
      dec(i);
    end;
    if (i=0)then s:='1'+s else s[i]:=chr(ord(s[i])+1);
    res:=(res+solve)mod base;
    writeln(res);
  end;
  close(output);close(input);
end.