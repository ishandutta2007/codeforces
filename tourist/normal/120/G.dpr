{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,t,i,m,it,g,k,j,q,rt,need: longint;
  c,kg: array [0..333] of longint;
  gg,d: array [0..333,0..333] of longint;
  a,b: array [0..333,0..3] of longint;
  name: array [0..333] of ansistring;
  good: array [0..333] of boolean;

function next(x:longint):longint;
begin
  repeat
    inc(x);
    if x > m then x:=1;
  until good[x];
  next:=x;
end;

begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  read(n,t);
  for i:=1 to n do read(a[i,1],b[i,1],a[i,2],b[i,2]);
  readln(m);
  for i:=1 to m do
  begin
    readln(name[i]);
    readln(c[i]);
    good[i]:=True;
  end;
  fillchar(d,sizeof(d),0);
  it:=0; g:=0; k:=1;
  while g < m do
  begin
    i:=it mod (2*n);
    if i < n then j:=1 else
    begin
      j:=2;
      dec(i,n);
    end;
    inc(i);
    q:=3-j;
    rt:=t;
    while (rt > 0) and (g < m) do
    begin
      need:=c[k]-(a[i,j]+b[i,q])-d[i,k];
      if need < 1 then need:=1;
      if need <= rt then
      begin
        rt:=rt-need;
        inc(kg[i]);
        gg[i,kg[i]]:=k;
        good[k]:=False;
        inc(g);
        if g = m then break;
        k:=next(k);
      end else
      begin
        inc(d[i,k],rt);
        k:=next(k);
        break;
      end;
    end;
    inc(it);
  end;
  for i:=1 to n do
  begin
    write(kg[i]);
    for j:=1 to kg[i] do write(' ',name[gg[i,j]]);
    writeln;
  end;
  close(input);
  close(output);
end.