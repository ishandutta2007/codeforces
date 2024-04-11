
#include <bits/stdc++.h>
using namespace std;
// Either globally or in a single class:
static char buf[450 << 20];
void* operator new(size_t s) {
    static size_t i = sizeof buf;
    assert(s < i);
    return (void*)&buf[i -= s];
}
void operator delete(void*) {}
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct vertex {
	vertex * l, * r;
	int sum;
 
	vertex (int val)
		: l(NULL), r(NULL), sum(val)
	{ }
 
	vertex (vertex * l, vertex * r)
		: l(l), r(r), sum(0)
	{
		if (l)  sum += l->sum;
		if (r)  sum += r->sum;
	}
};
 
vertex * build () {
	return new vertex (0);
}
 
int get_sum (vertex * t, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && tr == r)
		return t->sum;
	int tm = (tl + tr) / 2;
	if(t->l==NULL) t->l = new vertex(0);
	if(t->r==NULL) t->r = new vertex(0);
	return get_sum (t->l, tl, tm, l, min(r,tm))
		+ get_sum (t->r, tm+1, tr, max(l,tm+1), r);
}
 
vertex * update (vertex * t, int tl, int tr, int pos, int new_val) {
	if(pos == 1e9+7) return t;
	if (tl == tr) return new vertex (t->sum+new_val);
	int tm = (tl + tr) / 2;
	if (pos <= tm){
		if(t->l==NULL) t->l = new vertex(0);
		return new vertex (
				update (t->l, tl, tm, pos, new_val),
				t->r
			);
	}
	else{
		if(t->r==NULL) t->r = new vertex(0);
		return new vertex (
				t->l,
				update (t->r, tm+1, tr, pos, new_val)
			);
	}
}
// Node describes a node in the tree.
struct Node {
    // Array* index.
    int idx;

    // Value stored at index.
    int value;

    // Array* unique indentifier.
    int uid;

    // Reference to left subtree
    Node* left;

    // Reference to right subtree
    Node* right;

    Node() {
        idx = 0;
        value = 0;
        uid = 0;
        left = right = nullptr;
    }

    Node(int i, int v, int u) {
        idx = i;
        value = v;
        uid = u;
        left = right = nullptr;
    }
};

// PersistentArray persistent array using balanced binary tree (through
// randomization).
class PersistentArray {
public:
    PersistentArray() {
        root_ = nullptr;
        detached_ = false;
    }

    PersistentArray(unsigned int size) {
        size_ = size;
        detached_ = true;
        vector<int> ids(size_ - 1);
        iota(begin(ids), end(ids), 1);

        // Randomize indices to raise the chances of having a balanced tree.
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(begin(ids), end(ids), default_random_engine(seed));

        // Create entries for all indices
        root_ = new Node(0, 0, 0);
        for (int id : ids) {
            root_ = create(root_, id, 0);
        }
    }

    // Copy constructor
    PersistentArray(const PersistentArray& other) {
        this->size_ = other.size_;
        this->detached_ = false;
        this->root_ = other.root_;
    }

    // Asignment operator
    PersistentArray& operator=(const PersistentArray& other) {
        this->size_ = other.size_;
        this->detached_ = false;
        this->root_ = other.root_;
        return *this;
    }

    // Set sets value at index idx, i.e. A[idx] = value.
    void Set(int idx, int value) {
        if (!detached_) {
            // Copy-on-write, detach tree when a write operation is performed.
            root_ = setAndDetach(root_, idx, value);
            detached_ = true;
        } else {
            setValue(root_, idx, value);
        }
    }

    // Get returns the value at index idx, i.e., A[idx].
    int Get(int idx) {
        return get(root_, idx);
    }


    // clean frees tree, it only deletes those nodes that were created for this
    // tree, i.e., it skips shared nodes.
    void clean(Node* root, int uid) {
        if (root == nullptr) {
            return;
        }

        if (root->left && root->left->uid == uid) {
            clean(root->left, uid);
            delete root->left;
        }

        if (root->right && root->right->uid == uid) {
            clean(root->right, uid);
            delete root->right;
        }
    }

    // Destructor
    ~PersistentArray() {
        if (detached_ && root_) {
            clean(root_, root_->uid);
            delete root_;
        }
    }

private:
    // Array* size
    int size_;

    // Flag that indicates if we should create a copy of the array*.
    bool detached_;

    // Entry point to the tree.
    Node* root_;

    // create creates entry for index idx, with value 0 and uid.
    Node* create(Node* root, int idx, int uid) {
        if (root == nullptr) {
            return new Node(idx, 0, uid);
        }

        if (idx < root->idx) {
            root->left = create(root->left, idx, uid);
        } else {
            root->right = create(root->right, idx, uid);
        }
        return root;
    }

    // setValue sets value at index idx, i.e. A[idx] = value.
    void setValue(Node* root, int idx, int value) {
        if (root == nullptr) {
            return;
        }
        if (idx == root->idx) {
            root->value = value;
            return;
        }

        if (idx < root->idx) {
            setValue(root->left, idx, value);
        } else {
            setValue(root->right, idx, value);
        }
    }

    // setAndDetach sets A[idx] = value and copies the path all the way up to
    // the root so that the original array* remains unchanged.
    Node* setAndDetach(Node* root, int idx, int value) {
        if (root == nullptr) {
            return root;
        }
        Node* node = nullptr;
        if (idx == root->idx) {
            node = new Node(idx, value, root->uid + 1);
            node->left = root->left;
            node->right = root->right;
            return node;
        }

        if (idx < root->idx) {
            Node* l = setAndDetach(root->left, idx, value);
            if (l != nullptr) {
                node = new Node(root->idx, root->value, l->uid);
                node->left = l;
                node->right = root->right;
            }
        } else {
            Node* r = setAndDetach(root->right, idx, value);
            if (r != nullptr) {
                node = new Node(root->idx, root->value, r->uid);
                node->left = root->left;
                node->right = r;
            }
        }
        return node;
    }

    // get returns the value at index idx, i.e., A[idx].
    int get(Node* root, int idx) {
        // Returns 0 for non-existent indices.
        if (root == nullptr) {
            return 0;
        }

        if (idx == root->idx) {
            return root->value;
        }

        if (idx < root->idx) {
            return get(root->left, idx);
        } else {
            return get(root->right, idx);
        }
    }
};
const int N = 1e9;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int q;cin>>q;
	vertex* tree[q+1];
	vertex* temp;
	PersistentArray pa(100009);
	rep(i,100009) pa.Set(i,1e9+7);
	PersistentArray array[100009];
	array[0] =pa;
	tree[0] = build();
	map<string,int> m;
	int cnt =1;
	repA(i,1,q){
		string s;cin>>s;
		if(s=="set"){
			cin>>s;
			int x;cin>>x;
			if(m.find(s)!=m.end()) temp = update(tree[i-1],1,N,array[i-1].Get(m[s]),-1);
			else temp = tree[i-1],m[s] = cnt,cnt++;
			array[i] = array[i-1];
			array[i].Set(m[s],x);
			tree[i] = update(temp,1,N,x,1);
		}
		else if(s=="remove"){
			cin>>s;
			int x = 1e9+7;
			if(m.find(s)!=m.end()&&array[i-1].Get(m[s])!=1e9+7) temp = update(tree[i-1],1,N,array[i-1].Get(m[s]),-1);
			else temp = tree[i-1];
			if(m.find(s)==m.end()) m[s] = cnt,cnt++;
			array[i] = array[i-1];
			array[i].Set(m[s],x);
			tree[i] = temp;
		}
		else if(s=="query"){
			cin>>s;
			tree[i] = tree[i-1];
			array[i] = array[i-1];
			if(m.find(s)==m.end()||array[i].Get(m[s])==1e9+7) cout<<-1<<endl;
			else cout<<get_sum(tree[i-1],1,N,1,array[i].Get(m[s])-1)<<endl;
		}
		else{
			int x;cin>>x;
			tree[i] = tree[i-x-1];
			array[i] = array[i-x-1];
		}
	}
	return 0;
}