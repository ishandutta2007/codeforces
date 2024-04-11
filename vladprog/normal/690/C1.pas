var
  n,m,a,b,i:longint;
  par,size:array[1..1000]of longint;

function find(k:longint):longint;
begin
  if par[k]<>k
    then par[k]:=find(par[k]);
  find:=par[k]
end;

begin
  read(n,m);
  if n<>m+1 then
    begin
      writeln('no');
      halt
    end;
  for i:=1 to n do
    begin
      par[i]:=i;
      size[i]:=1
    end;
  for i:=1 to m do
    begin
      read(a,b);
      a:=find(a);
      b:=find(b);
      if a=b
        then
          begin
            writeln('no');
            halt
          end
        else
          begin
            if size[a]<size[b]
              then par[a]:=b
              else par[b]:=a;
            inc(size[a],size[b]);
            size[b]:=size[a]
          end
    end;
  writeln('yes')
end.