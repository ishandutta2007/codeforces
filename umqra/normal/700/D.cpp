#include <bits/stdc++.h>

using namespace std;

struct DynamicHuffmanNode {
  int weight;
  int parent;
  int symbol;
  int l, r;
  DynamicHuffmanNode() : weight(), parent(), symbol(), l(-1), r(-1) {}
  DynamicHuffmanNode(int w, int p, int s) : weight(w), parent(p), symbol(s), l(-1), r(-1) {}
};

struct DynamicHuffman {
  int total_weight;
  vector<DynamicHuffmanNode> nodes;
  vector<pair<int, int>> range_node;
  vector<int> symbol_node;

  DynamicHuffman(int size) : total_weight(), nodes(), range_node(), symbol_node() {
    nodes.reserve(size);
    range_node = vector<pair<int, int>>(size, make_pair(-1, -1));
    symbol_node = vector<int>(size, -1);
  }

  void clear() {
    total_weight = 0;
    nodes.clear();
    fill(range_node.begin(), range_node.end(), make_pair(-1, -1));
    fill(symbol_node.begin(), symbol_node.end(), -1);
  }

  int code_length() {
    if (nodes.size() == 0) {
      return 0;
    }
    return total_weight - nodes[0].weight;
  }
  void print() {
    cout << total_weight << endl;
    for (auto &&n : nodes) {
      cout << n.weight << ":" << n.parent << ":" << n.symbol << "(" << n.l << "," << n.r << ")" << endl;
    }
    /*
    cout << "leftmost:" << endl;
    for (auto &&e : leftmost_node) {
      cout << e.first << " " << e.second << endl;
    }
    cout << "rightmost:" << endl;
    for (auto &&e : rightmost_node) {
      cout << e.first << " " << e.second << endl;
    }
    */
  }
  void add(int symbol) {
    if (symbol_node[symbol] == -1) {
      add_node(symbol);
    }
    increment(symbol_node[symbol]);
  }
  void remove(int symbol) {
    decrement(symbol_node[symbol]);
    if (nodes.back().weight == 0) {
      int parent = nodes.back().parent;
      auto node = nodes[parent];
      swap_nodes(parent, (int)nodes.size() - 3);
      swap_nodes(min(node.l, node.r), (int)nodes.size() - 2);

      symbol_node[nodes.back().symbol] = -1;
      range_node[0] = make_pair(-1, -1);
      nodes.pop_back();

      auto duplicate = nodes.back();
      symbol_node[nodes.back().symbol] = -1;
      range_node[nodes.back().weight].second--;
      nodes.pop_back();

      total_weight -= duplicate.weight;
      nodes.back().symbol = duplicate.symbol;
      nodes.back().l = nodes.back().r = -1;
      set_symbol(duplicate.symbol, (int)nodes.size() - 1);
    }
  }
  void decrement(int node_id) {
    if (node_id == -1) {
      return;
    }
    total_weight--;

    int target_id = change_weight(node_id, -1);
    nodes[target_id].weight--;
    decrement(nodes[target_id].parent);
  }
  void increment(int node_id) {
    if (node_id == -1) {
      return;
    }
    total_weight++;

    int target_id = change_weight(node_id, +1);
    nodes[target_id].weight++;
    increment(nodes[target_id].parent);
  }

  int change_weight(int node_id, int delta) {
    int weight = nodes[node_id].weight;
    auto range = range_node[weight];
    if (range.first == range.second) {
      range_node[weight] = make_pair(-1, -1);
    } else {
      if (delta > 0) {
        range_node[weight].first++;
      } else {
        range_node[weight].second--;
      }
    }
    int target_id = delta > 0 ? range.first : range.second;
    swap_nodes(node_id, target_id);
    int update = weight + delta;
    if (range_node[update].first == -1) {
      range_node[update] = make_pair(target_id, target_id);
    } else if (delta > 0) {
      range_node[update].second = target_id;
    } else {
      range_node[update].first = target_id;
    }
    return target_id;
  }
  void swap_nodes(int a, int b) {
    if (a == b) {
      return;
    }
    swap(nodes[a].symbol, nodes[b].symbol);
    swap(nodes[a].l, nodes[b].l);
    swap(nodes[a].r, nodes[b].r);
    set_symbol(nodes[a].symbol, a);
    set_symbol(nodes[b].symbol, b);
    set_parent(nodes[a].l, a);
    set_parent(nodes[a].r, a);
    set_parent(nodes[b].l, b);
    set_parent(nodes[b].r, b);
  }
  void set_parent(int a, int p) {
    if (a == -1) {
      return;
    }
    nodes[a].parent = p;
  }
  void set_symbol(int symbol, int node_id) {
    if (symbol == -1) {
      return;
    }
    symbol_node[symbol] = node_id;
  }
  void add_node(int symbol) {
    int last_id = (int)nodes.size() - 1;
    auto node = DynamicHuffmanNode(0, last_id, symbol);
    if (nodes.size() == 0) {
      nodes.push_back(node);
      set_symbol(symbol, (int)nodes.size() - 1);
      range_node[0] = make_pair((int)nodes.size() - 1, (int)nodes.size() - 1);
      return;
    } 
    DynamicHuffmanNode duplicate{};
    {
      auto &last = nodes[last_id];
      total_weight += last.weight;
      duplicate = DynamicHuffmanNode(last.weight, last_id, last.symbol);
      last.symbol = -1;
      last.l = last_id + 1;
      last.r = last_id + 2;
    }
    nodes.push_back(duplicate);
    nodes.push_back(node);
    range_node[0] = make_pair((int)nodes.size() - 1, (int)nodes.size() - 1);
    range_node[duplicate.weight].second = (int)nodes.size() - 2;
    set_symbol(duplicate.symbol, (int)nodes.size() - 2);
    set_symbol(symbol, (int)nodes.size() - 1);
  }
};

struct Query {
  int l, r, id;
  Query(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
};

int main() {
  /*
  auto huffman = DynamicHuffman();
  huffman.add(1);
  huffman.add(2);
  huffman.add(1);
  huffman.add(3);
  huffman.add(1);
  huffman.add(2);
  huffman.add(1);
  cout << huffman.code_length() << endl;
  huffman.print();
  */

  int n;
  scanf("%d", &n);
  vector<int> values = {};
  values.reserve(n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    values.push_back(a);
  }
  int q;
  scanf("%d", &q);

  vector<Query> queries = {};
  auto answers = vector<int>(q, 0);
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    queries.emplace_back(l, r, i);
  }

  auto colors = vector<int>(n, 0);
  int position = 0;
  for (int i = 300; position < n; i += 0) {
    int initial = position;
    for (int s = 0; s < i && position < n; s++) {
      colors[position++] = initial;
    }
  }
  sort(queries.begin(), queries.end(), [&colors](const Query &a, const Query&b) {
    int ba = colors[a.l];
    int bb = colors[b.l];
    if (ba != bb) {
      return ba < bb;
    }
    return a.r < b.r;
  });
  
  int build_l = 0;
  int build_r = 0;
  auto huffman = DynamicHuffman(100000 + 1);
  int processed = 0;
  int operations = 0;
  for (auto &query : queries) {
    processed++;
    if (processed % 1000 == 0) {
      cerr << "processed " << processed << "(" << operations << ")" << endl;
    }
    // cout << query.id << endl;
    
    if (query.r < build_r - 1) {
      huffman.clear();
      build_l = build_r = query.l;
    }

    for (int i = build_r; i <= query.r; i++) {
      operations++;
      huffman.add(values[i]);
 //     huffman.print();
    }
//    huffman.print();
    build_r = query.r + 1;

    if (build_l < query.l) {
      for (int i = build_l; i < query.l; i++) {
        operations++;
        huffman.remove(values[i]);
      }
    } else {
      for (int i = query.l; i < build_l; i++) {
        operations++;
        huffman.add(values[i]);
      }
    }
    build_l = query.l;
    answers[query.id] = huffman.code_length();
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", answers[i]);
  }

  return 0;
}