{$macro+}
{ $define free}

{$ifdef free}
uses math;
{$endif}

var
  n,i,j,s,t:longint;
  a:array[1..50,1..50]of longint;
  ok:boolean;

begin
  read(n);
  for i:=1 to n do
    for j:=1 to n do
      read(a[i,j]);
  for i:=1 to n do
    for j:=1 to n do
      begin
        if a[i,j]=1 then continue;
        ok:=false;
        for s:=1 to n do
          begin
            if s=i then continue;
            for t:=1 to n do
              if(t<>j)and(a[s,j]+a[i,t]=a[i,j]) then
                begin
                  ok:=true;
                  break
                end;
            if ok then break
          end;
        if not ok then
          begin
            writeln('No');
            halt
          end
      end;
  writeln('Yes')
end.