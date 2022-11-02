const
  MAXN=100500;
var
  kp,j,n,i:longint;
  x:string;
  p:array[0..MAXN]of longint;
  was:array[0..MAXN]of boolean;
  function mult(a:string;b:longint):string;
    var
      res:string;
      i,c,r:longint;
    begin
      r:=0;
      res:='';
      for i:=length(a)downto 1 do begin
        c:=ord(a[i])-48;
        c:=c*b+r;
        r:=c div 10;
        c:=c mod 10;
        res:=chr(c+48)+res;
      end;
      while (r>0)do begin
        res:=chr(r mod 10+48)+res;
        r:=r div 10;
      end;
      mult:=res;
    end;
begin
  read(n);
  if (n<3)then begin
    writeln(-1);
    exit;
  end;
  fillchar(was,sizeof(was),true);
  kp:=0;
  for i:=2 to MAXN do
    if (was[i])then begin
      inc(kp);
      p[kp]:=i;
      for j:=2 to MAXN div i do
        was[i*j]:=false;
      if (kp=n)then break;
    end;
  x:='1';
  for i:=1 to n-1 do x:=mult(x,p[i]);
  writeln(x);
  for i:=1 to n-1 do
    writeln(p[i]*p[n]);
end.