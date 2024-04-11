{$r-,q-,s-,i-,o+}
var
  was:array[0..555]of boolean;
  d:array[0..555,0..555]of boolean;
  n,m,i,t:longint;
  ss,ff:array[0..55555]of longint;
  procedure dfs(x:longint);
    var
      i:longint;
    begin  
      was[x]:=true;
      for i:=1 to n do 
        if (d[x][i])and(not was[i])then dfs(i);
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m);
  fillchar(d,sizeof(d),false);
  for i:=1 to m do begin
    read(ss[i],ff[i]);
    d[ss[i],ff[i]]:=true;
    d[ff[i],ss[i]]:=true;
  end;
  if (n<>m)then begin
    writeln('NO');
    exit;
  end;
  for t:=1 to m do begin
    d[ss[t],ff[t]]:=false;
    d[ff[t],ss[t]]:=false;
    fillchar(was,sizeof(was),false);
    dfs(1);
    for i:=1 to n do 
      if (not was[i])then begin
        was[1]:=false;
        break;
      end;
    if (was[1])then begin
      writeln('FHTAGN!');
      exit;
    end;
    d[ss[t],ff[t]]:=true;
    d[ff[t],ss[t]]:=true;
  end;
  writeln('NO');
  close(output);close(input);
end.